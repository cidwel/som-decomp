.setcpu "65816"
.segment "CODE"
.org $867B
map_control_0c867b:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
