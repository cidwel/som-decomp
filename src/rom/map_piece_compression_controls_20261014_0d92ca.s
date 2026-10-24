.setcpu "65816"
.segment "CODE"
.org $92CA
map_control_0d92ca:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
