.setcpu "65816"
.segment "CODE"
.org $A8BF
map_control_0ea8bf:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
