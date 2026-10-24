.setcpu "65816"
.segment "CODE"
.org $04A5
map_control_0e04a5:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
