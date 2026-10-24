.setcpu "65816"
.segment "CODE"
.org $8ACE
map_control_0c8ace:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
