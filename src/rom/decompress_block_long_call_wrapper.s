; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

decompress_block = $4C30

.segment "CODE"
.org $0014
decompress_block_long_call_wrapper:
    jsr decompress_block
    rtl
