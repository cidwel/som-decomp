.setcpu "65816"
.segment "CODE"
.org $A00F
map_control_0fa00f:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
