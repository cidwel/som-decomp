.setcpu "65816"
.segment "CODE"
.org $D647
map_control_0ed647:
    .byte $EC ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
