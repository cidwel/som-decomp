.setcpu "65816"
.segment "CODE"
.org $64FF
map_control_0e64ff:
    .byte $E1 ; previous-row copy count
