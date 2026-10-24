.setcpu "65816"
.segment "CODE"
.org $1256
map_control_0c1256:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
