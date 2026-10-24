.setcpu "65816"
.segment "CODE"
.org $0CCD
map_control_0f0ccd:
    .byte $E4 ; previous-row copy count
