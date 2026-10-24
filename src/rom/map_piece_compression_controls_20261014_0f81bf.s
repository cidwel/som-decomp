.setcpu "65816"
.segment "CODE"
.org $81BF
map_control_0f81bf:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
