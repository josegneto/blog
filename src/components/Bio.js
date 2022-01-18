import React from 'react';
import profilePic from '../assets/profile-pic.jpg';
import { rhythm } from '../utils/typography';
import { FaFastForward } from 'react-icons/fa';

class Bio extends React.Component {
  render() {
    return (
      <div
        style={{
          display: 'flex',
          marginBottom: rhythm(2),
        }}
      >
        <img
          src={profilePic}
          alt={`José Neto`}
          style={{
            marginRight: rhythm(1 / 2),
            marginBottom: 0,
            width: rhythm(2),
            height: rhythm(2),
            borderRadius: '50%',
          }}
        />
        <p style={{ maxWidth: 310 }}>
          Personal blog by{' '}
          <a href="https://josegneto.github.io" style={{textDecoration : 'none'}}>José Neto</a>
          <br></br>Electrical Engineer
          <br></br>
          <a
            href="https://josegneto.github.io"
            target="_blank"
            rel="noopener noreferrer"

          >
            josegneto.github.io
          </a>
          
          <p> Based on{' '}
            {<a
              href="https://overreacted.io"
              target="_blank"
            >
              overreacted
            </a>} by Dan Abramov</p>
        </p>
      </div>
    );
  }
}

export default Bio;
