.setcpu "65816"
.segment "CODE"
.org $BE18
map_control_0ebe18:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
