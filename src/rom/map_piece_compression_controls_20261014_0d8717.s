.setcpu "65816"
.segment "CODE"
.org $8717
map_control_0d8717:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
