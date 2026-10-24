.setcpu "65816"
.segment "CODE"
.org $A4F5
map_control_0ea4f5:
    .byte $E5 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
