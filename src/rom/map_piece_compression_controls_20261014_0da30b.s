.setcpu "65816"
.segment "CODE"
.org $A30B
map_control_0da30b:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
