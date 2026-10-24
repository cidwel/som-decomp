.setcpu "65816"
.segment "CODE"
.org $617E
map_control_0d617e:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
