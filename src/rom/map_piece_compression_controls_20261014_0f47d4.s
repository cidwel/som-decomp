.setcpu "65816"
.segment "CODE"
.org $47D4
map_control_0f47d4:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
