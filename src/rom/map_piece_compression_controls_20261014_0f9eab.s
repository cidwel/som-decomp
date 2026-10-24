.setcpu "65816"
.segment "CODE"
.org $9EAB
map_control_0f9eab:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
