# China Air Quality Scraper for Drupal 7

This code scrapes and air quality readings (AQI, PMI 2.5, etc.) from aqicn.org

## How to Install

* Install Dependencies: In order to install you'll need a Drupal 7 setup and have added several dependencies include feeds, feeds tamper, entity api, views, views data export
* Add "China Air Quality Scraper" feature to your modules directory
* Enable this module. 
* After go to your-site-name.com/import and select one of the importers. For example, "Chengdu."
* Add the url to your target city or monitoring state. For example, http://aqicn.org/city/chengdu/
* Profit! 

## How It Works

* This code periodically goes to those urls, looks at the html and pulls the readings. 
* This data is then stored to the database. 

## Why did I make this? 

I made about a year ago and forgot about it. The air was bad and I wanted to collect this data to have for later reference. 

Interested in building some cool with Drupal or other tools, send me an email or contact me at my company at [Int3c.com](http://int3c.com)

For more fun data and tracking projects, check out my personal blog, [www.markwk.com](www.markwk.com)


