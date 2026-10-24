.setcpu "65816"
.segment "CODE"
.org $656A
map_control_0d656a:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
