.setcpu "65816"
.segment "CODE"
.org $6253
map_control_0f6253:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
