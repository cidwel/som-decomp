.setcpu "65816"
.segment "CODE"
.org $1945
map_control_0f1945:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
