.setcpu "65816"
.segment "CODE"
.org $0A57
map_control_0e0a57:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
