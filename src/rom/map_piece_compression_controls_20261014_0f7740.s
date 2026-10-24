.setcpu "65816"
.segment "CODE"
.org $7740
map_control_0f7740:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
