.setcpu "65816"
.segment "CODE"
.org $769E
map_control_0d769e:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
