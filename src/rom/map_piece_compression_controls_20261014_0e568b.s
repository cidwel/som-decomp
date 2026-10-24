.setcpu "65816"
.segment "CODE"
.org $568B
map_control_0e568b:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $F1 ; progressive-copy count
