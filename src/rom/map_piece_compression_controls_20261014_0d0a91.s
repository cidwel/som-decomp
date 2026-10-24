.setcpu "65816"
.segment "CODE"
.org $0A91
map_control_0d0a91:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
