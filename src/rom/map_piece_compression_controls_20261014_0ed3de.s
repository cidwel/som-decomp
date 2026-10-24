.setcpu "65816"
.segment "CODE"
.org $D3DE
map_control_0ed3de:
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
