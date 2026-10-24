.setcpu "65816"
.segment "CODE"
.org $A1C4
map_control_0ea1c4:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
