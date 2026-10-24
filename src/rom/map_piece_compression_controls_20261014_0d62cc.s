.setcpu "65816"
.segment "CODE"
.org $62CC
map_control_0d62cc:
    .byte $E1 ; previous-row copy count
