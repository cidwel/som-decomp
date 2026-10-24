.setcpu "65816"
.segment "CODE"
.org $7732
map_control_0f7732:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
