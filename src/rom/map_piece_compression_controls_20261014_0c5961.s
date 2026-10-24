.setcpu "65816"
.segment "CODE"
.org $5961
map_control_0c5961:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
