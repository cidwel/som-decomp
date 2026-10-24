.setcpu "65816"
.segment "CODE"
.org $BB9F
map_control_0fbb9f:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
