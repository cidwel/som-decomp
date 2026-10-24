.setcpu "65816"
.segment "CODE"
.org $8FD5
map_control_0c8fd5:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
