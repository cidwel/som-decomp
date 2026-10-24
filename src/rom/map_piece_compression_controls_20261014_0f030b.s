.setcpu "65816"
.segment "CODE"
.org $030B
map_control_0f030b:
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
