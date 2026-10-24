.setcpu "65816"
.segment "CODE"
.org $1DB1
map_control_0e1db1:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
