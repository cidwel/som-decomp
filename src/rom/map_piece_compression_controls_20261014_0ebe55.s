.setcpu "65816"
.segment "CODE"
.org $BE55
map_control_0ebe55:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
