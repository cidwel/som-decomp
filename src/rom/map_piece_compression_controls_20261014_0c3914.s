.setcpu "65816"
.segment "CODE"
.org $3914
map_control_0c3914:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
