.setcpu "65816"
.segment "CODE"
.org $7A91
map_control_0e7a91:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
