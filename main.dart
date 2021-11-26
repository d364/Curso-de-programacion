import 'dart:async';
import 'dart:convert';

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

void main() => runApp(MyApp());




Future<List<Photo>> fetchPhotos(http.Client client) async {
  final response = await client.get('https://www.flickr.com/services/feeds/photos_public.gne?format=json&nojsoncallback=1');
  return compute(parsePhotos, response.body);
}

// A function that converts a response body into a List<Photo>.
List<Photo> parsePhotos(String responseBody) {
  var parsed = jsonDecode(responseBody);
  return parsed['items'].map<Photo>((json) => Photo.fromJson(json)).toList();
}

class PhotosList extends StatelessWidget {
  final List<Photo> photos;

  PhotosList({Key key, this.photos}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ListView.builder(
      itemCount: photos.length,
      itemBuilder: (context, index) {
        return Image.network(photos[index].url);
      },
    );
  }
}


class Photo {
  final String url;
  Photo({this.url});
  factory Photo.fromJson(Map<String, dynamic> json) {
    return Photo(
      url: json['media']['m'] as String,
    );
  }
}

class MyApp extends StatelessWidget {

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        home: Scaffold(
            body: FutureBuilder<List<Photo>>(
              future: fetchPhotos(http.Client()),
              builder: (context, snapshot) {

                if (snapshot.hasError) print(snapshot.error);

                return snapshot.hasData
                    ? PhotosList(photos: snapshot.data)
                    : Center(child: CircularProgressIndicator());
              },
            ),
        )
    );
  }
}


