.setcpu "65816"
.segment "CODE"
.org $81E7
map_control_0d81e7:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
