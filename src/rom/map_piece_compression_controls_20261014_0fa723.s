.setcpu "65816"
.segment "CODE"
.org $A723
map_control_0fa723:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
