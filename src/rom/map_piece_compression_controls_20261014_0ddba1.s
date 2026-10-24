.setcpu "65816"
.segment "CODE"
.org $DBA1
map_control_0ddba1:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
