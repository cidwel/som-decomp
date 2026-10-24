# Native SPC music receive and channel initialization

The readable `MusicInitialization` model reconstructs **287 instruction bytes**: SPC0CF1..0DE4 (244 bytes, physical ROMC3123B..C3132E) and its complete SPC0DE5..0E0F channel helper (43 bytes, ROMC3132F..C31359). Separate fixed mnemonic sources regenerate both bodies exactly against the headerless USA rev0 ROM. Physical ROM addresses and SPC runtime addresses remain distinct; this is SPC700 source, with no duplicate 65816 credit.

The original entry keys off the DSP, resets timer zero to 40, waits on its counter and restores target 24. It receives the real command's echo/volume fields, acknowledges the next packet, configures the complete native echo region and calls the existing transfer receiver. It then resets the specified voice, fade, pending and mix fields, performs the native echo wait/filter publication, copies the song header and relocates each active channel from the song's declared base to 1A14. Empty channels are identified by the exact marker in header bytes 12/13. Active channels retain their original order and bit masks and call the complete channel helper, including its upper RAM resets and low RAM control-byte writes. The initial master volume and fade use the original parameter nibbles and full native 1011 handler.

The entry does not return to a fabricated caller: it sets SP=FF and jumps to the actual main loop at 0279. The comparison stops at that boundary. Timer zero/one reads have explicit polling profiles; DSP/port writes are ordered and compared, while elapsed timing and audible waveforms are outside this functional proof.

The prepared capture receives all 59 actual ROM song payloads through native two-byte packets; no song bytes are preinstalled in RAM or saved to repository files. Packet tokens wrap through 255 to 1 and retain their payload until the receiver's next token poll. The complete original instructions execute without hooks, including echo, transfer, channel and fade dependencies. Random initial RAM, registers, flags, DSP and ports are compared in full, except the four native nested-call/saved-status stack bytes 01EC..01EF. CPU/SP/PC, peripheral control/targets, read counts and producer state are compared as well.

The fixture selects volume 0F and parameter low nibble 4, with high nibbles 0/4/8/C. It transfers song data at 1A00 without instrument/sample-cache uploads: those tables are not consumed before this entry reaches 0279. Echo length and filter are zero in this directed chain. Every eighth case explicitly tests the supported end-header bit 3 skip path; the existing 65816 music sender normally finishes with zero header flags, so that skip variant is a receiver-domain case, not evidence of a normal song-load request from that sender. The main command receiver 0CAF, sample/instrument load composition and subsequent note sequencing remain open.

The captured proof passed **59 complete original song calls**, across 296 PC/P states, with 12 recorded dependency hashes, 41763 ordered I/O writes and 391 active song channels initialized. Both independently assembled mnemonic bodies match all 287 bytes. The process finished terminal exit zero; its report is `data/spc_audio_music_initialization.json`.

```sh
python3 tools/spc_audio_music_initialization.py 'baserom.sfc' \
  --json data/spc_audio_music_initialization.json
```
