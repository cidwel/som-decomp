.setcpu "65816"
.segment "CODE"
.org $56ED
map_control_0f56ed:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E2 ; previous-row copy count
