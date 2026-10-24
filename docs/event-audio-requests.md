# Event sound command and native sender

Status:394 original calls passed with532PC/M/Xstates; matching-source recovery is now authorized by this complete direct-entry proof. C1F0EC..C1F10D contains34instruction bytes.

`EventAudioRequests` reconstructs opcode40's direct handler: command comes fromDP05, the operand at script cursor+2 becomes1E01, and the word at cursor+3 becomes1E02/03. The handler advances the low16bits ofDPD1 by5 without incrementing the bank byteDPD3, then calls the complete nativeC30004 sender. Incoming M8/X8,D0/DB7E matches the event interpreter's dispatch context. Music, effects and other commands use the recovered sender models; no sender hook is proposed.

The existing event parser identifies197 distinct SOUND instruction positions across2048 event IDs, representing122 distinct four-byte requests. Their command values are1,2,80,F1,F2. The successful394-call comparison crosses every actual script position with two flag/acknowledgement contexts, starts with an idle audio token0, and compares fullWRAM outside only instruction-observed stack bytes, finalCPU/context, all video/peripheral state and every ordered APU write. Actual script payloads remain runtime ROM input and are never saved.

A model-only preflight accepts the real effect request atC908AE and preserves the script bank while advancing the cursor. The subsequent full original comparison passed all394cases with no model changes. Arbitrary direct pages, relocated/malformed scripts, bus timing, simultaneousSPC execution and waveform synthesis remain outside this verified direct-entry contract.
