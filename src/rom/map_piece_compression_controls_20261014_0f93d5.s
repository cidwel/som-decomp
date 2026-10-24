.setcpu "65816"
.segment "CODE"
.org $93D5
map_control_0f93d5:
    .byte $C2 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
