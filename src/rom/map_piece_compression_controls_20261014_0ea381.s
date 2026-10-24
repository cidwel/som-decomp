.setcpu "65816"
.segment "CODE"
.org $A381
map_control_0ea381:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
