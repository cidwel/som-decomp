.setcpu "65816"
.segment "CODE"
.org $6AF6
map_control_0f6af6:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
