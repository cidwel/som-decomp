.setcpu "65816"
.segment "CODE"
.org $2893
map_control_0f2893:
    .byte $E0 ; previous-row copy escape
    .byte $D6 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
