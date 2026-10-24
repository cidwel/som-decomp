.setcpu "65816"
.segment "RODATA"
; Native consumer data at $C2B7DA; no graphics payload.
ui_focus_marker_0:
.byte $01 ; four-byte sprite record count
.byte $FC, $FC ; signed screen offsets
.word $3F80 ; native tile/attribute word
ui_focus_marker_1:
.byte $04 ; four-byte sprite record count
.byte $FA, $FF ; signed screen offsets
.word $3F8C ; native tile/attribute word
.byte $FA, $FA ; signed screen offsets
.word $3F8B ; native tile/attribute word
.byte $FF, $FE ; signed screen offsets
.word $3F8E ; native tile/attribute word
.byte $FF, $FA ; signed screen offsets
.word $3F8D ; native tile/attribute word
ui_focus_marker_2:
.byte $04 ; four-byte sprite record count
.byte $F9, $FF ; signed screen offsets
.word $3F8C ; native tile/attribute word
.byte $F9, $F9 ; signed screen offsets
.word $3F8B ; native tile/attribute word
.byte $FF, $FF ; signed screen offsets
.word $3F8E ; native tile/attribute word
.byte $FF, $F9 ; signed screen offsets
.word $3F8D ; native tile/attribute word
ui_focus_marker_3:
.byte $04 ; four-byte sprite record count
.byte $00, $00 ; signed screen offsets
.word $3F8E ; native tile/attribute word
.byte $00, $F8 ; signed screen offsets
.word $3F8D ; native tile/attribute word
.byte $F8, $00 ; signed screen offsets
.word $3F8C ; native tile/attribute word
.byte $F8, $F8 ; signed screen offsets
.word $3F8B ; native tile/attribute word
ui_focus_marker_4:
.byte $0A ; four-byte sprite record count
.byte $FA, $FA ; signed screen offsets
.word $3F84 ; native tile/attribute word
.byte $FA, $FF ; signed screen offsets
.word $3F85 ; native tile/attribute word
.byte $FF, $02 ; signed screen offsets
.word $3F8A ; native tile/attribute word
.byte $FF, $F6 ; signed screen offsets
.word $3F87 ; native tile/attribute word
.byte $FA, $F6 ; signed screen offsets
.word $3F83 ; native tile/attribute word
.byte $FA, $02 ; signed screen offsets
.word $3F86 ; native tile/attribute word
.byte $FF, $FA ; signed screen offsets
.word $3F88 ; native tile/attribute word
.byte $FF, $FF ; signed screen offsets
.word $3F89 ; native tile/attribute word
.byte $F5, $00 ; signed screen offsets
.word $3F82 ; native tile/attribute word
.byte $F5, $F8 ; signed screen offsets
.word $3F81 ; native tile/attribute word
ui_focus_marker_5:
.byte $0A ; four-byte sprite record count
.byte $00, $04 ; signed screen offsets
.word $3F8A ; native tile/attribute word
.byte $00, $F4 ; signed screen offsets
.word $3F87 ; native tile/attribute word
.byte $FA, $04 ; signed screen offsets
.word $3F86 ; native tile/attribute word
.byte $FA, $F4 ; signed screen offsets
.word $3F83 ; native tile/attribute word
.byte $00, $FA ; signed screen offsets
.word $3F88 ; native tile/attribute word
.byte $00, $FF ; signed screen offsets
.word $3F89 ; native tile/attribute word
.byte $FA, $FF ; signed screen offsets
.word $3F85 ; native tile/attribute word
.byte $FA, $FA ; signed screen offsets
.word $3F84 ; native tile/attribute word
.byte $F4, $00 ; signed screen offsets
.word $3F82 ; native tile/attribute word
.byte $F4, $F8 ; signed screen offsets
.word $3F81 ; native tile/attribute word
ui_focus_marker_6:
.byte $0A ; four-byte sprite record count
.byte $F9, $06 ; signed screen offsets
.word $3F86 ; native tile/attribute word
.byte $F9, $FE ; signed screen offsets
.word $3F85 ; native tile/attribute word
.byte $F9, $FA ; signed screen offsets
.word $3F84 ; native tile/attribute word
.byte $F9, $F2 ; signed screen offsets
.word $3F83 ; native tile/attribute word
.byte $00, $06 ; signed screen offsets
.word $3F8A ; native tile/attribute word
.byte $00, $FE ; signed screen offsets
.word $3F89 ; native tile/attribute word
.byte $00, $FA ; signed screen offsets
.word $3F88 ; native tile/attribute word
.byte $00, $F2 ; signed screen offsets
.word $3F87 ; native tile/attribute word
.byte $F2, $00 ; signed screen offsets
.word $3F82 ; native tile/attribute word
.byte $F2, $F8 ; signed screen offsets
.word $3F81 ; native tile/attribute word
ui_focus_marker_7:
.byte $0A ; four-byte sprite record count
.byte $F0, $00 ; signed screen offsets
.word $3F82 ; native tile/attribute word
.byte $F0, $F8 ; signed screen offsets
.word $3F81 ; native tile/attribute word
.byte $F8, $08 ; signed screen offsets
.word $3F86 ; native tile/attribute word
.byte $F8, $00 ; signed screen offsets
.word $3F85 ; native tile/attribute word
.byte $F8, $F8 ; signed screen offsets
.word $3F84 ; native tile/attribute word
.byte $F8, $F0 ; signed screen offsets
.word $3F83 ; native tile/attribute word
.byte $00, $08 ; signed screen offsets
.word $3F8A ; native tile/attribute word
.byte $00, $00 ; signed screen offsets
.word $3F89 ; native tile/attribute word
.byte $00, $F8 ; signed screen offsets
.word $3F88 ; native tile/attribute word
.byte $00, $F0 ; signed screen offsets
.word $3F87 ; native tile/attribute word
