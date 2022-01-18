import React from 'react';

import { rhythm } from '../utils/typography';

class Footer extends React.Component {
  render() {
    return (
      <footer
        style={{
          marginTop: rhythm(2.5),
          paddingTop: rhythm(1),
        }}
      >
        {/* <div style={{ float: 'right' }}>
          <a href="/rss.xml" target="_blank" rel="noopener noreferrer">
            rss
          </a>
        </div> */}
        {/* <a
          href="https://mobile.twitter.com/dan_abramov"
          target="_blank"
          rel="noopener noreferrer"
        >
          twitter
        </a>{' '}
        &bull;{' '} */}
        {/* <a
          href="https://github.com/josegneto"
          target="_blank"
          rel="noopener noreferrer"
          
        >
          github
        </a> */}
        {/* <p>Layout from {' '}
        { <a
          href="https://overreacted.io"
          target="_blank"
        >
           overreacted.io
        </a> } by Dan Abramov.</p> */}
        
      </footer>
    );
  }
}

export default Footer;
