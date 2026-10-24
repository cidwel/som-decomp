.setcpu "65816"
.segment "CODE"
.org $BAAB
map_control_0dbaab:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
