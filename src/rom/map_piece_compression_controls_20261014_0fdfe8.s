.setcpu "65816"
.segment "CODE"
.org $DFE8
map_control_0fdfe8:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E1 ; previous-row copy count
