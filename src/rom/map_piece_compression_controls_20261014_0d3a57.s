.setcpu "65816"
.segment "CODE"
.org $3A57
map_control_0d3a57:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
