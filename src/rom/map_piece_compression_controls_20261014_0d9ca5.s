.setcpu "65816"
.segment "CODE"
.org $9CA5
map_control_0d9ca5:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
