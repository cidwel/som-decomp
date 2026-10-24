.setcpu "65816"
.segment "CODE"
.org $ADEF
map_control_0eadef:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E4 ; previous-row copy count
